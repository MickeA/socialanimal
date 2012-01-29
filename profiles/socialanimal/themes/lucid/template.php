<?php
/**
 * @file
 * template file for Lucid.
 */

/**
 * Change the default meta content-type tag to the shorter HTML5 version.
 */
function lucid_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );
}

/**
 * Changes the search form to use the HTML5 "search" input attribute.
 */
function lucid_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

/**
 * Process variables for the html tag.
 */
function lucid_process_html_tag(&$vars) {
  $tag = &$vars['element'];
  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant type attribute and CDATA comments.
    unset($tag['#attributes']['type'], $tag['#value_prefix'], $tag['#value_suffix']);

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }
}

/**
 * Uses RDFa attributes if the RDF module is enabled.
 * Lifted from Adaptivetheme for D7, full credit to Jeff Burnz.
 * ref: http://drupal.org/node/887600
 */
function lucid_preprocess_html(&$vars) {
  global $language;

  // First check if libraries module exists.
  // Look for html5 and responsive js files for IE. Use them if found, else
  // use external source.
  if (module_exists('libraries', 1.0)) {
    $respond_path = libraries_get_path('Respond') . '/respond.min.js';
    $html5_path = libraries_get_path('html5') . '/html5.js';
    $vars['lucid_lib']['ie']['respond_path'] = file_exists($respond_path) ? base_path() . $respond_path : 'https://raw.github.com/scottjehl/Respond/master/respond.min.js';
    $vars['lucid_lib']['ie']['html5_path'] = file_exists($html5_path) ? base_path() . $html5_path : 'http://html5shim.googlecode.com/svn/trunk/html5.js';
  }
  if (module_exists('rdf')) {
    $vars['doctype'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN">' . "\n";
    $vars['rdf']->version = 'version="HTML+RDFa 1.1"';
    $vars['rdf']->namespaces = $vars['rdf_namespaces'];
    $vars['rdf']->profile = ' profile="' . $vars['grddl_profile'] . '"';
  }
  else {
    $vars['doctype'] = '<!DOCTYPE html>' . "\n";
    $vars['rdf']->version = '';
    $vars['rdf']->namespaces = '';
    $vars['rdf']->profile = '';
  }

  // Attributes for html element.
  $vars['html_attributes'] = 'lang="' . $language->language . '" dir="' . $language->dir . '"';
}


/**
 * Modify the Panels default output to remove the panel separator.
 */
function lucid_panels_default_style_render_region($vars) {
  $output = '';
  $output .= implode($vars['panes']);
  return $output;
}

/**
 * Implementation of template_preprocess_panels_pane()
 */
function lucid_preprocess_panels_pane(&$vars) {
  // Only use the pane type as a class.
  unset($vars['classes_array']);
  $vars['classes_array'] = array(
    strtr($vars['pane']->subtype, '_', '-'),
    'clearfix',
  );
  if (isset($vars['pane']->css['css_class'])) {
    $vars['classes_array'][] = $vars['pane']->css['css_class'];
  }
}

/**
 * Implementation of template_preprocess_fields()
 */
function lucid_preprocess_field(&$vars) {
  // Only use the field class.
  unset($vars['classes_array']);
  $vars['classes_array'] = array(
    strtr($vars['element']['#field_name'], '_', '-'),
  );
}

/**
 * Implementation of template_preprocess_node()
 */
function lucid_preprocess_node(&$vars) {
  // Only use the a node class and the node type as a class.
  unset($vars['classes_array']);
  $vars['classes_array'] = array(
    'node',
    $vars['type'],
  );
}

/**
 * Implementation of template_preprocess_views_view()
 */
function lucid_preprocess_views_view(&$vars) {
  // Change the classes string for a view, with only the view name and the
  // display name.
  unset($vars['classes_array']);
  $vars['classes_array'] = array(
    'view',
    'view-' . $vars['css_name'],
    'view-display-' . strtr($vars['display_id'], '_', '-'),
  );
}

/**
 * Return a themed breadcrumb trail.
 */
function lucid_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<nav class="breadcrumb" role="navigation">' . implode(' » ', $breadcrumb) . '</nav>';
    return $output;
  }
}

/**
 * Override of theme_menu_tree().
 */
function lucid_menu_tree($variables) {
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}
