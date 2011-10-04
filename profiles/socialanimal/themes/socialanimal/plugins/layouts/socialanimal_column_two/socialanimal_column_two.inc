<?php

$plugin = array(
  'title' => t('brsv two columns'),
  'theme' => 'brsv_column_two',
  'icon' => 'brsv-column-two.png',
  'category' => 'brsv',
  'regions' => array(
    'main' => t('Main'),
    'aside_alpha' => t('Aside alpha'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_one().
 */
function precision_preprocess_brsv_column_two(&$vars) {
  precision_check_layout_variables($vars);
}
