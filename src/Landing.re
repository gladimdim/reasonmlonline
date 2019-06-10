let component = ReasonReact.statelessComponent("Landing");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h3> (ReasonReact.string("What is this site about")) </h3>
      <p>
        (
          ReasonReact.string(
            "Weekly Reason provides a subscription to latest news about ReasonML programming language and ecocystem.",
          )
        )
      </p>
      <p>
        <a href="#archive"> (ReasonReact.string("Archive of Issues")) </a>
      </p>
      <p>
        (ReasonReact.string("Go to "))
        <a href="http://news.reasonml.online">
          (ReasonReact.string("Weekly Reason Subscription Page"))
        </a>
        (ReasonReact.string(" to subscribe to our weekly newsletter."))
      </p>
      <p>
        (
          ReasonReact.string(
            "Your email will be used only for receiving Weekly ReasonML newsletter.",
          )
        )
      </p>
      <p>
        (
          ReasonReact.string(
            "This site is not affiliated with ReasonML team and Facebook.",
          )
        )
      </p>
      <h4> (ReasonReact.string("RSS Feed")) </h4>
      <a href="/rss/feed.xml">
        (ReasonReact.string("Click here to subscribe to RSS feed."))
      </a>
      <h4> (ReasonReact.string("Who runs this")) </h4>
      <p>
        <a href="https://twitter.com/DmytroGladkyi">
          (ReasonReact.string("Dmytro Gladkyi"))
        </a>
      </p>
    </div>,
};
