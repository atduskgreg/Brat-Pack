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

path_to_app = destination
app_name = destination.split("/").last

template = ERB.new <<-TEMP
#!/usr/bin/env ruby

require '<%= path_to_app %>'
require 'vegas'

Vegas::Runner.new(Sinatra::Application, '<%= app_name %>')})
TEMP

# raise "THIS IS THE OUTPUT: #{template.result(binding)}"
`touch #{ruby_dir}/apps/#{app_name}`
`echo "#{template.result(binding)}" > #{ruby_dir}/apps/#{app_name}`


# File.open("#{ruby_dir}/apps/#{app_name}", "w"){|f| f<< }

`chmod a+x #{ruby_dir}/apps/#{app_name}`

