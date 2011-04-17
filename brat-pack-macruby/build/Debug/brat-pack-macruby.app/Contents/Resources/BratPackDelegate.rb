# BPWebViewDelegate.rb
# brat-pack-macruby
#
# Created by Greg Borenstein on 4/16/11.
# Copyright 2011 __MyCompanyName__. All rights reserved.

require 'Project'
require 'ProjectManager'

class BratPackDelegate
  attr_accessor :web_view, :js_engine

  def applicationDidFinishLaunching(notification)  
    path = NSBundle.mainBundle.resourcePath.stringByAppendingPathComponent("home.html")
    
    page_url = NSURL.URLWithString(path)
    web_view.mainFrame.loadRequest(NSURLRequest.requestWithURL(page_url))
    
    web_view.frameLoadDelegate = self


    @project_manager = ProjectManager.new
    #@project_manager.name = "joe"
    @project_manager.projects = Project.create_many_projects
     #@projects = Project.create_many_projects   
  end
  
  def webView(view, didFinishLoadForFrame:frame)
    @js_engine = view.windowScriptObject # windowScriptObject
    @js_engine.setValue(@project_manager, forKey: "ProjectManager")
    @project_manager.respondsToSelector("start:")
    @project_manager.respondsToSelector("stop:")

    @project_manager.respondsToSelector("projects")
    #@project_manager.respondsToSelector("name")

    #@js_engine.setValue(@projects, forKey: "projects")
    
    # JIT the method, no colon at the end of the method since the selector doesn't
    # take arguments.
    
    #puts @project_manager.start("foo")
    

    
    @project_manager.projects.each_with_index do |project,i|
      project.respondsToSelector("name")
      project.respondsToSelector("running")
      project.respondsToSelector("id")
      
     #@js_engine.evaluateWebScript("addProject(ProjectManager.projects()[#{i}])")
    end
    
    
    
    @js_engine.evaluateWebScript('displayProjects()')

    
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
