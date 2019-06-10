let component = ReasonReact.statelessComponent("TwitterLink");
let make = (~link: string, ~label=?, _children) => {
  ...component,
  render: _self =>
    <a href=link>
      (
        ReasonReact.string(
          switch (label) {
          | Some(v) => v
          | None => link
          },
        )
      )
    </a>,
};
