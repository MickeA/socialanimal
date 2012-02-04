<?php

// Remove default panel-separator div
function socialanimal_panels_default_style_render_region($vars) {
  $output = '';
//  $output .= '<div class="region region-' . $vars['region_id'] . '">';
  //we do not need panel-separator
  $output .= implode($vars['panes']);
//  $output .= '</div>';
  return $output;
}