# BPWebViewDelegate.rb
# brat-pack-macruby
#
# Created by Greg Borenstein on 4/16/11.
# Copyright 2011 __MyCompanyName__. All rights reserved.

class BPWebViewDelegate
  attr_accessor :page_url, :web_view

  def initialize()
    @page_url = "http://google.com"
    @web_view.setURI(NSURL.urlFromString(@page_url))
  end

  def self.page_url
    "http://google.com"
  end
end
