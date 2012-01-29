<?php
/**
 * @file
 * Example profile file.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function socialanimal_form_install_configure_form_alter(&$form, $form_state) {

  // Pre-populate some fields in configure site form.
  $form['site_information']['site_name']['#default_value'] = 'Social Animal'; //$_SERVER['SERVER_NAME'];
  $form['site_information']['site_mail']['#default_value'] = 'michael@nodeone.se';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'michael@nodeone.se';
  $form['server_settings']['site_default_country']['#default_value'] = 'SE';
  $form['server_settings']['site_default_timezone']['#default_value'] = 'Europe/Stockholm';

}



// There is no way of having sub-profiles in Drupal currently,
// so if we want to use something from the NodeStream profile,
// we have to do so by including it. This is not at all required,
// and you can remove this if you don't want to use anything in the profile.
//require_once(DRUPAL_ROOT . '/profiles/nodestream/nodestream.profile');
//
///**
// * Implements hook_install_tasks().
// */
//function ns_example_profile_install_tasks() {
//  // NodeStream uses the Default config module for a lot of it's configuration.
//  // In order to get that configuration in place, we add an install task.
//  // This gives us complete control over when the configuration is added.
//  // NodeStream already defines this task, so we can just use the function from
//  // that profile.
//  return array(
//    'nodestream_finish' => array(
//      'display_name' => st('Apply configuration'),
//      'display' => TRUE,
//      'type' => 'batch',
//    ),
//  );
//}
