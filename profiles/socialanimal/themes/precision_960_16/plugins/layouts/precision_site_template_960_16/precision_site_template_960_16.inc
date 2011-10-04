<?php

$plugin = array(
  'title' => t('Precision site template (960/16)'),
  'theme' => 'precision_site_template_960_16',
  'icon' => 'precision-site-template-960-16.png',
  'category' => 'Precision (960/16)',
  'regions' => array(
    'branding' => t('Branding'),
    'nav' => t('Navigation'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);

/**
 * Preprocess the site template layout.
 */
function precision_preprocess_precision_site_template_960_16(&$vars) {
  precision_check_layout_variables($vars);
}
