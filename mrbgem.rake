MRuby::Gem::Specification.new('minierb') do |spec|
  spec.bins = ['minierb']
  spec.license = 'MIT'
  spec.authors = 'winebarrel'
  spec.add_dependency 'mruby-env', mgem: 'mruby-env'
  spec.add_dependency 'mruby-erb', github: 'k0kubun/mruby-erb'
end
