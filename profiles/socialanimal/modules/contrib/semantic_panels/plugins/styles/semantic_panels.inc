<?php
/**
 * @file
 */

$plugin = array(
  'title' => t('Semantic'),
  'description' => t('Semantic Style.'),

  'render region' => 'semantic_panels_render_region',
  'settings form' => 'semantic_panels_settings_form',

  'render pane' => 'semantic_panels_render_pane',
  'pane settings form' => 'semantic_panels_pane_settings_form',
);

/**
 *
 */
function semantic_panels_settings_form($settings) {
  $form = array();

  $elements = _semantic_panels_get_elements();

  $form['separator']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add separator'),
    '#description' => t('Enable/disable separator between panes.'),
    '#default_value' => $settings['separator']['active'],
  );
  $form['separator']['element_type'] = array(
    '#title' => t('HTML element'),
    '#type' => 'select',
    '#options' => $elements,
    '#default_value' => $settings['separator']['element_type'],
    '#dependency' => array(
      'edit-settings-separator-active' => array(1),
    ),
    '#tree' => TRUE,
  );
  $form['separator']['show_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['separator']['element_class']),
    '#dependency' => array(
      'edit-settings-separator-active' => array(TRUE),
    ),
    '#tree' => TRUE,
  );
  $form['separator']['element_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#default_value' => $settings['separator']['element_class'],
    '#dependency' => array(
      'edit-settings-separator-show-css' => array(TRUE),
      'edit-settings-separator-active' => array(TRUE),
    ),
    '#dependency_count' => 2,
    '#tree' => TRUE,
  );

  return $form;
}

/**
 *
 */
function semantic_panels_pane_settings_form($settings) {
  $form = array();
  $elements = _semantic_panels_get_elements();

  $form['element_title'] = array(
    '#type' => 'fieldset',
    '#title' => t('Title settings'),
    '#weight' => 0,
    '#collapsible' => TRUE,
  );
  $form['element_title']['type'] = array(
    '#type' => 'select',
    '#title' => t('HTML element'),
    '#options' => $elements,
    '#default_value' => $settings['element_title']['type'],
    '#fieldset' => 'element_title',
  );
  $form['element_title']['class_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['element_title']['class']),
    '#fieldset' => 'element_title',
  );
  $form['element_title']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class(es)'),
    '#default_value' => $settings['element_title']['class'],
    '#dependency' => array(
      'edit-settings-element-title-class-enable' => array(TRUE),
    ),
    '#fieldset' => 'element_title',
  );

  $form['element_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content settings'),
    '#weight' => 1,
    '#collapsible' => TRUE,
  );
  $form['element_content']['type'] = array(
    '#type' => 'select',
    '#title' => t('HTML element'),
    '#options' => $elements,
    '#default_value' => $settings['element_content']['type'],
    '#fieldset' => 'element_content',
  );
  $form['element_content']['class_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['element_content']['class']),
    '#fieldset' => 'element_content',
  );
  $form['element_content']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class(es)'),
    '#default_value' => $settings['element_content']['class'],
    '#dependency' => array(
      'edit-settings-element-content-class-enable' => array(TRUE),
    ),
    '#fieldset' => 'element_content',
  );

  $form['element_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wrapper settings'),
    '#weight' => 2,
    '#collapsible' => TRUE,
  );
  $form['element_wrapper']['type'] = array(
    '#type' => 'select',
    '#title' => t('HTML element'),
    '#options' => $elements,
    '#default_value' => $settings['element_wrapper']['type'],
    '#fieldset' => 'element_wrapper',
  );
  $form['element_wrapper']['class_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['element_wrapper']['class']),
    '#fieldset' => 'element_wrapper',
  );
  $form['element_wrapper']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class(es)'),
    '#default_value' => $settings['element_wrapper']['class'],
    '#dependency' => array(
      'edit-settings-element-wrapper-class-enable' => array(TRUE),
    ),
    '#fieldset' => 'element_wrapper',
  );

  $form['add_default_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add default classes'),
    '#default_value' => $settings['add_default_classes'] || TRUE,
    '#description' => t('This will add default classes on every element except the wrapper element(to not break contextual links)'),
    '#weight' => 3,
  );

  return $form;
}

/**
 *
 */
function theme_semantic_panels_render_region($vars) {
  $settings = $vars['settings'];

  $markup = $output = '';

  if (!empty($settings['separator']) && $settings['separator']['active'] === 1) {
    $markup = "<{$settings['separator']}></{$settings['separator']}>";
  }

  $output = implode($markup, $vars['panes']);

  drupal_alter('semantic_panels_region', $output, $vars);

  return $output;
}

/**
 *
 */
function theme_semantic_panels_render_pane($vars) {
  return theme('semantic_panels_pane', $vars);
}
