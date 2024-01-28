# minierb

[![build](https://github.com/winebarrel/minierb/actions/workflows/ci.yml/badge.svg)](https://github.com/winebarrel/minierb/actions/workflows/ci.yml)

ERB cli built with mruby.

## Installation

Download binary from [releases page](https://github.com/winebarrel/minierb/releases/latest).

## Usage

```sh
$ echo '<%= 1 + 2 %>' | minierb
3

$ cat test.erb
<%- if true -%>
<%- user = ENV["USER"] -%>
<%= user %>
<%= user =~ /wa/ %>
<%- end -%>

$ minierb test.erb
sugawara
4
```
