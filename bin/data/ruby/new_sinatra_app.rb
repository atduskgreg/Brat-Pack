require 'fileutils'

ruby_dir = ARGV[0]
destination = ARGV[1]

destination = destination.gsub(' ', '\ ')
ruby_dir = ruby_dir.gsub(' ', '\ ')

parts = ruby_dir.split(/\//)
parts.pop
ruby_dir = parts.join("/")

`cp #{ruby_dir}/template/* #{destination}`
