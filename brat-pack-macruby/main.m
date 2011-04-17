//
//  main.m
//  brat-pack-macruby
//
//  Created by Greg Borenstein on 4/16/11.
//  Copyright __MyCompanyName__ 2011. All rights reserved.
//

#import <MacRuby/MacRuby.h>

int main(int argc, char *argv[])
{
    return macruby_main("rb_main.rb", argc, argv);
}
