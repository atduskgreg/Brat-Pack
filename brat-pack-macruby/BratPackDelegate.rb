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
    @project_manager.projects = Project.create_many_projects
  end
  
  def webView(view, didFinishLoadForFrame:frame)
    @js_engine = view.windowScriptObject # windowScriptObject
    @js_engine.setValue(@project_manager, forKey: "ProjectManager")
    @project_manager.respondsToSelector("start:")
    @project_manager.respondsToSelector("stop:")

    @project_manager.respondsToSelector("projects")
    
    @project_manager.projects.each_with_index do |project,i|
      project.respondsToSelector("name")
      project.respondsToSelector("running")
      project.respondsToSelector("id")
    end
    
    @js_engine.evaluateWebScript('displayProjects()')
  end

end
