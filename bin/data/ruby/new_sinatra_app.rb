require 'fileutils'
require 'erb'

ruby_dir = ARGV[0]
destination = ARGV[1]

destination = destination.gsub(' ', '\ ')
ruby_dir = ruby_dir.gsub(' ', '\ ')

parts = ruby_dir.split(/\//)
parts.pop
ruby_dir = parts.join("/")

`cp #{ruby_dir}/template/* #{destination}`


vegas_template = open("template/vegas_bin.erb").read

path_to_app = destination
app_name = destination.split("/").last

File.open("#{ruby_dir}/apps/#{app_name}", "w"){|f| f<< template.result(binding)}

`chmod a+x "#{ruby_dir}/apps/#{app_name}`

