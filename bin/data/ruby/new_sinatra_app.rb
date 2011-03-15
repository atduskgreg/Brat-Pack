require 'fileutils'

ruby_dir = ARGV[0]
destination = ARGV[1]

destination.gsub!(' ', '\ ')

FileUtils.cp_r("#{ruby_dir}/template", destination)
