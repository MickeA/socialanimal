This module allows Views to access and filter on menu item information in three
ways:

* A new default argument, fetching the currently active mlid (menu link ID).
  Optionally it can fetch the entire active menu trail on the form 1+2+3, or
  the entire trail *excluding* the currently active mlid.
* A filter handler, allowing to filter an integer field on the currently active
  mlid.
* A filter handler, allowing to filter an integer field on any parent mlid.

Currenly only the default argument plugin is implemented.
This module works well with the (yet to be written) Menu Item Reference module.
