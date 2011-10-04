<?php
!function_exists('profiler_v2') ? require_once('libraries/profiler/profiler.inc') : FALSE;
profiler_v2('socialanimal');


/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function socialanimal_form_install_configure_form_alter(&$form, $form_state) {

  // Pre-populate some fields in configure site form.
  $form['site_information']['site_name']['#default_value'] = 'Social Animal';
  $form['site_information']['site_mail']['#default_value'] = 'michael@nodeone.se';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'michael@nodeone.se';
  $form['server_settings']['site_default_country']['#default_value'] = 'SE';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Stockholm';

}
