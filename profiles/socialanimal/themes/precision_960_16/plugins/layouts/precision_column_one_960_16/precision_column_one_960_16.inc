<?php

$plugin = array(
  'title' => t('Precision one column (960/16)'),
  'theme' => 'precision_column_one_960_16',
  'icon' => 'precision-column-one-960-16.png',
  'category' => 'Precision (960/16)',
  'regions' => array(
    'main' => t('Main'),
  ),
);

/**
 * Implementation of theme_preprocess_precision_column_one().
 */
function precision_preprocess_precision_column_one_960_16(&$vars) {
  precision_check_layout_variables($vars);
}
