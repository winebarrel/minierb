# minierb

[![build](https://github.com/winebarrel/minierb/actions/workflows/ci.yml/badge.svg)](https://github.com/winebarrel/minierb/actions/workflows/ci.yml)

Single binary ERB template processor built with mruby.

## Installation

Download binary from [releases page](https://github.com/winebarrel/minierb/releases/latest).

```sh
$ wget https://github.com/winebarrel/minierb/releases/download/v0.1.1/minierb-aarch64-darwin.gz
$ gunzip minierb-aarch64-darwin.gz
$ mv minierb-aarch64-darwin minierb
$ chmod +x minierb
```

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
