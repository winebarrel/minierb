# minierb

[![build](https://github.com/winebarrel/minierb/actions/workflows/ci.yml/badge.svg)](https://github.com/winebarrel/minierb/actions/workflows/ci.yml)

Single binary ERB template processor built with mruby.

## Installation

Download binary from [releases page](https://github.com/winebarrel/minierb/releases/latest).

```sh
$ wget https://github.com/winebarrel/minierb/releases/download/vX.X.X/minierb-XXX-XX.gz
$ gunzip minierb-XXX-XXX.gz
$ mv minierb-XXX-XXX minierb
$ chmod +x minierb
```

## Usage

```sh
$ echo '<%= 1 + 2 %>' | minierb
3
```

```erb
<%-
to = ENV["MAIL_TO"]
priorities = ENV["PRIORITIES"].split(",").map(&:strip)
-%>
From:  James <james@example.com>
To:  <%= to %>
Subject:  Addressing Needs

<%= to[/\w+/] %>:

Just wanted to send a quick note assuring that your needs are being
addressed.

I want you to know that my team will keep working on the issues,
especially:

<%# ignore numerous minor requests -- focus on priorities %>
<%- priorities.each do |priority| -%>
* <%= priority %>
<%- end -%>

Thanks for your patience.

James
```
```sh
$ export MAIL_TO="Community Spokesman <spokesman@example.com>"
$ export PRIORITIES="Run Ruby Quiz,Document Modules,Answer Questions on Ruby Talk"

$ minierb mail.erb
From:  James <james@example.com>
To:  Community Spokesman <spokesman@example.com>
Subject:  Addressing Needs

Community:

Just wanted to send a quick note assuring that your needs are being
addressed.

I want you to know that my team will keep working on the issues,
especially:


* Run Ruby Quiz
* Document Modules
* Answer Questions on Ruby Talk

Thanks for your patience.

James
```
