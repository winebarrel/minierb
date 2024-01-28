MRUBY_BUILD_TARGET = ENV["MRUBY_BUILD_TARGET"]

if !MRUBY_BUILD_TARGET
  MRuby::Build.new do |conf|
    toolchain :gcc
    conf.gembox "default"
    conf.gem File.expand_path(File.dirname(__FILE__))
    conf.enable_test
  end
else
  MRuby::CrossBuild.new(MRUBY_BUILD_TARGET) do |conf|
    [conf.cc, conf.linker].each do |cc|
      cc.command = "zig cc -target #{MRUBY_BUILD_TARGET}"
    end
    conf.archiver.command = "zig ar"
    conf.host_target = MRUBY_BUILD_TARGET

    conf.gembox "default"
    conf.gem File.expand_path(File.dirname(__FILE__))
  end
end
