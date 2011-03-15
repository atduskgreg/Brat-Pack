require 'fileutils'

destination = ARGV[0]
FileUtils.cp_r("#{File.expand_path(File.dirname("."))}/template", destination)