# reasonml.online web site

## Install

Build and install everything needed:

```sh
yarn install
yarn run build-reason
yarn run build
```

## Deploy

```sh
yarn release
```

That should be enough to build new site. Nginx will auto-serve all these static files.
It also copies files from public folder into dat folder.

## Dat site

Dat site is available at https://weeklyreason-gladimdim.hashbase.io/
and
dat://64c6177bc6d9b9644f56cf56e2696879a68a2bc16b62e823a5cb7f08896b1b68

# Issuing new Issue Process

## Adding JS resources

* Add new <number>.json file to static/issues folder.
* Add new <number>-uk.json file to static/issues folder with Ukrainian version.
* Modify ArchiveIndex.re and add new link at top.
* Update public/rss/feed.xml with new issue.
* Run
```sh
yarn start
serve ./public
```
* Go to 188.226.204.136:8000 and verify how new issue is rendered.
* Add new <item> into public/rss/feed.xml file
* Commit changed files: <number>[-uk].json, feed.xml, ArchiveIndex.re
* Run production build
```sh
yarn release
```
Copy ./public/Index.js into ./dat/public
Copy ./public/issues/<number>*.json files into ./dat/public/issues
Copy ./public/rss/feed.xml into ./dat/public/rss9

* Post an update on @WeeklyReason Twitter
* Post an update on @WeeklkyReason@toot.cafe mastodon account.
