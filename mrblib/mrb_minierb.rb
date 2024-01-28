class Minierb
  def self.eval(src)
    ERB.new(src, nil, "-").result
  end
end

def __main__(argv)
  src = if ARGV.empty?
          STDIN.read
        else
          ARGV.map do |f|
            File.read(f)
          end
        end

  print Minierb.eval(src)
end
