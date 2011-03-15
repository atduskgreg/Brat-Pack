require 'fileutils'

destination = ARGV[0]

destination.gsub!(' ', '\ ')

FileUtils.cp_r("#{File.expand_path(File.dirname("."))}/template", destination)
