<?php
/**
 * @file
 * sa_image_slideshow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function sa_image_slideshow_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_to_frontpage_after_image_slideshow_node_save'] = entity_import('rules_config', '{ "rules_redirect_to_frontpage_after_image_slideshow_node_save" : {
      "LABEL" : "Redirect to frontpage after image slideshow node save",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Social Animal" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "slideshow_image" : "slideshow_image" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "\\u003cfront\\u003e" } } ]
    }
  }');
  return $items;
}
