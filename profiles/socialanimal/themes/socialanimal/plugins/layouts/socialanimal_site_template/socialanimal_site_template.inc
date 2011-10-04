<?php

$plugin = array(
  'title' => t('brsv site template'),
  'theme' => 'brsv_site_template',
  'icon' => 'brsv_site_template.png',
  'category' => 'brsv)',
  'regions' => array(
    'branding' => t('Branding'),
    'nav' => t('Navigation'),
    'main' => t('Main'),
    'aside_alpha' => t('Aside alpha'),
    'footer' => t('Footer'),
  ),
);

/**
 * Preprocess the site template layout.
 */
function precision_preprocess_brsv_site_template(&$vars) {
  precision_check_layout_variables($vars);
}
