type tIssue = {
  author: string,
  authorLink: string,
  summary: string,
  linkToArticle: string,
};

module Decode = {
  let decodeIssue = input: tIssue =>
    Json.Decode.{
      author: input |> field("author", string),
      authorLink: input |> field("authorLink", string),
      summary: input |> field("summary", string),
      linkToArticle: input |> field("linkToArticle", string),
    };
  let decodeIssues = input => input |> Json.Decode.array(decodeIssue);
};

type tLang = [ | `English | `Ukrainian];

type action =
  | DownloadIssue
  | UpdateLanguageFromURL(ReasonReact.Router.url)
  | ChangeLanguage(tLang)
  | RenderIssue(array(tIssue))
  | UpdateLanguage(tLang);

type state = {
  language: tLang,
  issue: option(array(tIssue)),
};

let getLanguageFromURL = (url: ReasonReact.Router.url) =>
  Js.String.includes("language=uk", url.hash) ? `Ukrainian : `English;

let getIssueSuffix = (lang: tLang): string =>
  switch (lang) {
  | `Ukrainian => "-uk"
  | `English => ""
  };

let component = ReasonReact.reducerComponent("Issue");

let make = (~issueNumber: int, _children) => {
  ...component,
  initialState: () => {
    issue: None,
    language:
      ReasonReact.Router.dangerouslyGetInitialUrl() |> getLanguageFromURL,
  },
  reducer: (action, state) =>
    switch (action) {
    | UpdateLanguageFromURL(url) =>
      ReasonReact.UpdateWithSideEffects(
        {...state, language: getLanguageFromURL(url)},
        (self => self.send(DownloadIssue)),
      )
    | ChangeLanguage(l) =>
      ReasonReact.UpdateWithSideEffects(
        {...state, language: l},
        (self => self.send(DownloadIssue)),
      )
    | DownloadIssue =>
      ReasonReact.SideEffects(
        (
          self =>
            Js.Promise.(
              Fetch.fetch(
                "./issues/"
                ++ string_of_int(issueNumber)
                ++ state.language->getIssueSuffix
                ++ ".json",
              )
              |> then_(Fetch.Response.json)
              |> then_(result => {
                   let decodedIssues = Decode.decodeIssues(result);
                   self.send(RenderIssue(decodedIssues));
                   Js.Promise.resolve();
                 })
              |> ignore
            )
        ),
      )
    | RenderIssue(issue) =>
      ReasonReact.Update({...state, issue: Some(issue)})
    | UpdateLanguage(lang) =>
      ReasonReact.SideEffects(
        (
          _ =>
            ReasonReact.Router.push(
              "#archive?issue="
              ++ string_of_int(issueNumber)
              ++ (
                switch (lang) {
                | `English => "&language=en"
                | `Ukrainian => "&language=uk"
                }
              ),
            )
        ),
      )
    },
  didMount: self => {
    self.send(DownloadIssue);
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        self.send(UpdateLanguageFromURL(url))
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: ({state, send}) =>
    switch (state.issue) {
    | Some(v) =>
      <div>
        <div>
          <MaterialUi.Button
            onClick=(
              _ =>
                send(
                  UpdateLanguage(
                    switch (state.language) {
                    | `Ukrainian => `English
                    | `English => `Ukrainian
                    },
                  ),
                )
            )
            color=`Primary
            style=(ReactDOMRe.Style.make(~float="right", ()))>
            (
              ReasonReact.string(
                switch (state.language) {
                | `Ukrainian => "English"
                | `English => {js|Українською|js}
                },
              )
            )
          </MaterialUi.Button>
        </div>
        <div style=(ReactDOMRe.Style.make(~clear="both", ()))>
          (
            Array.map(
              article =>
                MaterialUi.(
                  <Card
                    style=(ReactDOMRe.Style.make(~marginBottom="1rem", ()))>
                    <CardHeader
                      title=(ReasonReact.string(article.author))
                      subheader=(ReasonReact.string(article.authorLink))
                    />
                    <CardContent>
                      <p> (ReasonReact.string(article.summary)) </p>
                    </CardContent>
                    <CardActions>
                      <Button
                        size=`Small color=`Primary href=article.linkToArticle>
                        (ReasonReact.string(article.linkToArticle))
                      </Button>
                    </CardActions>
                  </Card>
                ),
              v,
            )
            |> ReasonReact.array
          )
        </div>
      </div>
    | None => <div />
    },
};

let jsIssueRe =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~issueNumber=jsProps##issueNumber, jsProps##children)
  );