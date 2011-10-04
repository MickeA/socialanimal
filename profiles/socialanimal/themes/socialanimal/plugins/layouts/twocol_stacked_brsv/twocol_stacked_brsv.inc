<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked BRSV (Less hacky)'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_stacked_brsv.png',
  'theme' => 'panels_twocol_stacked_brsv',
  'css' => 'twocol_stacked_brsv.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
