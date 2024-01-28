##
## Minierb Test
##

assert("Minierb#hello") do
  t = Minierb.new "hello"
  assert_equal("hello", t.hello)
end

assert("Minierb#bye") do
  t = Minierb.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Minierb.hi") do
  assert_equal("hi!!", Minierb.hi)
end
