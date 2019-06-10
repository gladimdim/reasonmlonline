type tMode = [ | `LandingPage | `ArchiveIndexView | `IssueView(int)];
type state = {mode: tMode};
type action =
  | UpdatedUrl(ReasonReact.Router.url)
  | ShowLandingPage
  | ShowArchiveIndexView
  | ShowIssueView(int);

let component = ReasonReact.reducerComponent("Weekly");

let handleClickOnIssue = (i: int) =>
  ReasonReact.Router.push("#archive?issue=" ++ string_of_int(i));

module Url = {
  [@bs.get] external hash : Dom.location => string = "";

  let getSearch = (hashed: string) => {
    let result = hashed |> Js.String.split("?");
    if (Array.length(result) > 1) {
      result[1];
    } else {
      result[0];
    };
  };
  let getSearchPairs = (search: string) => {
    let pairs = search |> Js.String.split("&");
    pairs
    |> Array.map(a => {
         let r = a |> Js.String.split("=");
         if (Array.length(r) > 1) {
           (r[0], r[1]);
         } else {
           (r[0], "");
         };
       });
  };
};

let getIssueNumberFromHashSearch = (hash: string) =>
  hash
  |> Url.getSearch
  |> Url.getSearchPairs
  |> Array.to_list
  |> List.filter(input =>
       switch (input) {
       | ("issue", _) => true
       | _ => false
       }
     )
  |> (
    fun
    | [(_a, b)] => int_of_string(b)
    | _ => 0
  );

let getModeFromUrl = (input: ReasonReact.Router.url) =>
  switch (Js.String.includes("archive", input.hash)) {
  | false => `LandingPage
  | true =>
    let issue = input.hash |> getIssueNumberFromHashSearch;
    Js.String.includes("issue", input.hash) ?
      `IssueView(issue) : `ArchiveIndexView;
  };

let make = _children => {
  ...component,
  initialState: () => {
    mode: ReasonReact.Router.dangerouslyGetInitialUrl() |. getModeFromUrl,
  },
  reducer: (action, _state) =>
    switch (action) {
    | UpdatedUrl(url) => ReasonReact.Update({mode: url |. getModeFromUrl})
    | ShowLandingPage =>
      ReasonReact.SideEffects((_self => ReasonReact.Router.push("/")))
    | ShowArchiveIndexView => ReasonReact.Update({mode: `ArchiveIndexView})
    | ShowIssueView(issueNumber) =>
      ReasonReact.Update({mode: `IssueView(issueNumber)})
    },
  render: self =>
    <div>
      <span onClick=(_ => self.send(ShowLandingPage))>
        MaterialUi.(
          <AppBar position=`Sticky color=`Primary>
            <Toolbar>
              <h2> (ReasonReact.string("Weekly Reason Newsletter")) </h2>
            </Toolbar>
          </AppBar>
        )
      </span>
      (
        switch (self.state.mode) {
        | `LandingPage => <Landing />
        | `ArchiveIndexView =>
          <ArchiveIndex clickedIssue=(i => handleClickOnIssue(i)) />
        | `IssueView(issueNumber) => <Issue issueNumber />
        }
      )
    </div>,
  didMount: self => {
    let watcherId =
      ReasonReact.Router.watchUrl(url => self.send(UpdatedUrl(url)));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
};
