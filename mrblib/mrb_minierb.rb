def __main__(argv)
  src = if ARGV.empty?
          STDIN.read
        else
          ARGV.map do |f|
            File.read(f)
          end.join
        end

  print ERB.new(src, nil, "-").result
end
