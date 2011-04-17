# ProjectManager.rb
# brat-pack-macruby
#
# Created by Greg Borenstein on 4/17/11.
# Copyright 2011 __MyCompanyName__. All rights reserved.

class ProjectManager
  attr_accessor :projects, :name
    
  def start(project)
    project.start
  end
  
  def stop(project)
    project.stop
    
  end

  def self.isSelectorExcludedFromWebScript(sel); false end

end