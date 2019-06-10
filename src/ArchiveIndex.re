let component = ReasonReact.statelessComponent("ArchiveIndex");

let make = (~clickedIssue, _children) => {
  ...component,
  render: _self =>
    <ul>
      (ReasonReact.string("Archive Index"))
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(28))>
          (ReasonReact.string("Issue #28 on 3rd of April 2019"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(27))>
          (ReasonReact.string("Issue #27 on 9th of March 2019"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(26))>
          (ReasonReact.string("Issue #26 on 22nd of February 2019"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(25))>
          (ReasonReact.string("Issue #25 on 17th of February 2019"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(24))>
          (ReasonReact.string("Issue #24 on 4th of January 2019"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(23))>
          (ReasonReact.string("Issue #23 on 14th of December 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(22))>
          (ReasonReact.string("Issue #22 on 22th of November 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(21))>
          (ReasonReact.string("Issue #21 on 12th of November 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(20))>
          (ReasonReact.string("Issue #20 on 28th of October 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(19))>
          (ReasonReact.string("Issue #19 on 20th of October 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(18))>
          (ReasonReact.string("Issue #18 on 14th of October 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(17))>
          (ReasonReact.string("Issue #17 on 28th of September 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(16))>
          (ReasonReact.string("Issue #16 on 21th of September 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(15))>
          (ReasonReact.string("Issue #15 on 14th of September 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(14))>
          (ReasonReact.string("Issue #14 on 6th of September 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(13))>
          (ReasonReact.string("Issue #13 on 25th of August 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(12))>
          (ReasonReact.string("Issue #12 on 17th of August 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(11))>
          (ReasonReact.string("Issue #11 on 10th of August 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(10))>
          (ReasonReact.string("Issue #10 on 3rd of August 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(9))>
          (ReasonReact.string("Issue #9 on 27th of July 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(8))>
          (ReasonReact.string("Issue #8 on 20th of July 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(7))>
          (ReasonReact.string("Issue #7 on 13th of July 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(6))>
          (ReasonReact.string("Issue #6 on 6th of July 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(5))>
          (ReasonReact.string("Issue #5 on 22nd of June 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(4))>
          (ReasonReact.string("Issue #4 on 15th of June 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(3))>
          (ReasonReact.string("Issue #3 on 7th of June 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(2))>
          (ReasonReact.string("Issue #2 on 1st of June 2018"))
        </p>
      </li>
      <li>
        <p className="fake-link" onClick=(_e => clickedIssue(1))>
          (ReasonReact.string("Issue #1 on 25th of May 2018"))
        </p>
      </li>
    </ul>,
};