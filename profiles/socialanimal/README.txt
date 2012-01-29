# Introduction
This is an example installation profile that uses NodeStream as a base.
It can be used as a template when creating new installation profiles on top of
NodeStream.

# Directory structure
The directory structure is the same as any profile,
the only difference is that we have added three symlinks:

modules/nodestream => ../../nodestream/modules
themes/nodestream => ../../nodestream/themes
libraries => ../nodestream/libraries

This let's us use all modules fetched by NodeStream,
and everything will be upgraded when NodeStream is upgraded.
