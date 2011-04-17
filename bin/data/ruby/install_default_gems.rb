password = ARGV[0]

gems = [
  "sinatra",
  "dm-core",
  "dm-migrations",
  "vegas"
]

gems.each do |gem_name|
  puts `echo "#{password}" | sudo gem install #{gem_name}`
end