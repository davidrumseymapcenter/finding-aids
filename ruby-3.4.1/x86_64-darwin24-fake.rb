# frozen_string_literal: true
# shareable_constant_value: literal
baseruby="./tool/missing-baseruby.bat"
_\
=begin
_=
ruby="${RUBY-$baseruby}"
case "$ruby" in "echo "*) $ruby; exit $?;; esac
case "$0" in /*) r=-r"$0";; *) r=-r"./$0";; esac
exec $ruby "$r" "$@"
=end
=baseruby
class Object
  remove_const :CROSS_COMPILING if defined?(CROSS_COMPILING)
  CROSS_COMPILING = RUBY_PLATFORM
  options = remove_const(:RUBY_DESCRIPTION)[/( \+[^\[\]\+]+)*(?= \[\S+\]\z)/]
  constants.grep(/^RUBY_/) {|n| remove_const n}
  RUBY_VERSION = "3.4.1"
  RUBY_RELEASE_DATE = "2024-12-25"
  RUBY_PLATFORM = "x86_64-darwin24"
  RUBY_PATCHLEVEL = 0
  RUBY_REVISION = "48d4efcb85000e1ebae42004e963b5d0cedddcf2"
  RUBY_COPYRIGHT = "ruby - Copyright (C) 1993-2024 Yukihiro Matsumoto"
  RUBY_ENGINE = "ruby"
  RUBY_ENGINE_VERSION = "3.4.1"
  RUBY_DESCRIPTION = "ruby 3.4.1 (2024-12-25 revision 48d4efcb85)#{options} [x86_64-darwin24]".freeze
end
builddir = File.dirname(File.expand_path(__FILE__))
libpathenv = libpathenv = "DYLD_LIBRARY_PATH"
preloadenv = preloadenv = "DYLD_INSERT_LIBRARIES"
libruby_so = libruby_so = "libruby.3.4.dylib.3.4.1"
srcdir = "."
top_srcdir = File.realpath(srcdir, builddir)
fake = File.join(top_srcdir, "tool/fake.rb")
eval(File.binread(fake), nil, fake)
ropt = "-r#{__FILE__}"
["RUBYOPT"].each do |flag|
  opt = ENV[flag]
  opt = opt ? ([ropt] | opt.b.split(/\s+/)).join(" ") : ropt
  ENV[flag] = opt
end
