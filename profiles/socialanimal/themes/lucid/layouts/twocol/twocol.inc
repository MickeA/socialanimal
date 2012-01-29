<?php
/**
 * @file
 * Definition of Lucid two col layout.
 */

$plugin = array(
  'title' => t('Two columns'),
  'theme' => 'twocol',
  'icon' => 'twocol.png',
  'category' => 'Lucid',
  'regions' => array(
    'header_alpha' => t('Header alpha'),
    'main' => t('Main'),
    'aside_beta' => t('Aside beta'),
    'footer_alpha' => t('Footer alpha'),
  ),
);
