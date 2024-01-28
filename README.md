# minierb   [![build](https://github.com/winebarrel/minierb/actions/workflows/ci.yml/badge.svg)](https://github.com/winebarrel/minierb/actions/workflows/ci.yml)
Minierb class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'winebarrel/minierb'
end
```
## example
```ruby
p Minierb.hi
#=> "hi!!"
t = Minierb.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
