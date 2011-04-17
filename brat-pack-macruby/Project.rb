# project.rb
# brat-pack-macruby
#
# Created by Greg Borenstein on 4/17/11.
# Copyright 2011 __MyCompanyName__. All rights reserved.

class Project
  attr_accessor :name, :pid, :path, :running, :id
  
  def initialize(name)
    @name = name
    @id = rand(10000)
    @running = false
  end

  def self.create_many_projects
    [Project.new("Color"), Project.new("Is the Floor Open?"), Project.new("Exegist")]
  end
  
  
  def start
    puts `say started #{self.name}`
    @running = true
  end
  
  def stop
    puts `say stopped #{self.name}`
    @running = false
  end
  
  def self.isSelectorExcludedFromWebScript(sel); false end

end