# BPWebViewDelegate.rb
# brat-pack-macruby
#
# Created by Greg Borenstein on 4/16/11.
# Copyright 2011 __MyCompanyName__. All rights reserved.

class Project
  attr_accessor :name
  
  def initialize(name)
    @name = name
  end

  def self.create_many_projects
    [Project.new("Color"), Project.new("Is the Floor Open?"), Project.new("Exegist")]
  end
  
 
  
  def start
    puts `say started #{self.name}`
  end
  
  def self.isSelectorExcludedFromWebScript(sel); false end

end

class ProjectManager
  attr_accessor :projects, :name
    
  def start(n)
    puts `say started: #{n}`
  end

  def self.isSelectorExcludedFromWebScript(sel); false end

end


class BratPackDelegate
  attr_accessor :web_view, :js_engine

  def applicationDidFinishLaunching(notification)  
    path = NSBundle.mainBundle.resourcePath.stringByAppendingPathComponent("home.html")
    
    page_url = NSURL.URLWithString(path)
    web_view.mainFrame.loadRequest(NSURLRequest.requestWithURL(page_url))
    
    web_view.frameLoadDelegate = self


    @project_manager = ProjectManager.new
    @project_manager.name = "joe"
    @project_manager.projects = Project.create_many_projects
        
  end
  
  def webView(view, didFinishLoadForFrame:frame)
    @js_engine = view.windowScriptObject # windowScriptObject
    @js_engine.setValue(@project_manager, forKey: "projectManager")
    @project_manager.respondsToSelector("start:")
    #@project_manager.respondsToSelector("projects")
    #@project_manager.respondsToSelector("name")

    #@js_engine.setValue(@projects, forKey: "projects")
    
    # JIT the method, no colon at the end of the method since the selector doesn't
    # take arguments.
    
    #puts @project_manager.start("foo")
    
    
    @project_manager.projects.each do |project|
    
      #project.respondsToSelector("start")
      #puts @js_engine.evaluateWebScript('project.name()')
      
      @js_engine.evaluateWebScript("addProject('#{project.name}')")
    end
    
    
    #puts @project_manager.name()
    #puts @js_engine.evaluateWebScript("projectManager.start_('cats')")
  
   #puts @js_engine.evaluateWebScript("projectManager.projects()[0].start()")
    #puts "js bridge test: "
    # trigger JS from Ruby
    #@js_engine.evaluateWebScript("$('body').text('phase 1');")
    # Evaluate JS from Ruby via the DOM
    #puts @js_engine.evaluateWebScript("projectManager.projects()")
    # Execute Ruby code from the DOM
    #@project.start

    #puts @js_engine.evaluateWebScript("project.start()")
  end

end
