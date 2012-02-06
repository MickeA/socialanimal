<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Single column'),
  'category' => t('Semantic Panels'),
  'icon' => 'onecol.png',
  'theme' => 'semantic_panels_onecol',
  'regions' => array('middle' => t('Middle')),
  'settings form' => 'semantic_panels_onecol_settings_form'
);

function semantic_panels_onecol_settings_form($display, $layout, $settings){

  $form = array();
  $elements = _semantic_panels_get_elements();

  // Code from views:
  // Some form elements belong in a fieldset for presentation, but can't
  // be moved into one because of the form_state['values'] hierarchy. Those
  // elements can add a #fieldset => 'fieldset_name' property, and they'll
  // be moved to their fieldset during pre_render.
  $form['#pre_render'][] = 'semantic_panels_pre_render_add_fieldset_markup';

  $form['layout_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout Settings'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['panel'] = array(
    '#type' => 'fieldset',
    '#title' => t('Panel Settings'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#fieldset' => 'layout_settings'
  );
  $form['panel']['element_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wrapper settings'),
    '#weight' => 2,
    '#collapsible' => TRUE,
  );
  $form['panel']['element_wrapper']['#pre_render'][] = 'semantic_panels_pre_render_add_fieldset_markup';

  $form['panel']['element_wrapper']['type'] = array(
    '#type' => 'select',
    '#title' => t('HTML element'),
    '#options' => $elements,
    '#default_value' => $settings['panel']['element_wrapper']['type']
  );
  $form['panel']['element_wrapper']['class_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['panel']['element_wrapper']['class'])
  );
  $form['panel']['element_wrapper']['class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class(es)'),
    '#default_value' => $settings['panel']['element_wrapper']['class'],
    '#dependency' => array(
      'edit-layout-settings-panel-element-wrapper-class-enable' => array(TRUE),
    )
  );

  foreach($layout['regions'] as $machine_name => $human_name){

    $form['regions'] = array(
      '#type' => 'fieldset',
      '#title' => t('Region Settings', array('@region_name' => $human_name)),
      '#weight' => 0,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#fieldset' => 'layout_settings'
    );

    $form['regions'][$machine_name] = array(
      '#type' => 'fieldset',
      '#title' => t('@region_name Region Settings', array('@region_name' => $human_name)),
      '#weight' => 0,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#fieldset' => 'regions'
    );

    $form['regions'][$machine_name]['element_wrapper'] = array(
      '#type' => 'fieldset',
      '#title' => t('Wrapper settings'),
      '#weight' => 2,
      '#collapsible' => TRUE,
    );
    $form['regions'][$machine_name]['element_wrapper']['type'] = array(
      '#type' => 'select',
      '#title' => t('HTML element'),
      '#options' => $elements,
      '#default_value' => $settings['regions'][$machine_name]['element_wrapper']['type']
    );
    $form['regions'][$machine_name]['element_wrapper']['class_enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create a CSS class'),
      '#default_value' => !empty($settings['regions'][$machine_name]['element_wrapper']['class'])
    );
    $form['regions'][$machine_name]['element_wrapper']['class'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class(es)'),
      '#default_value' => $settings['regions'][$machine_name]['element_wrapper']['class'],
      '#dependency' => array(
        'edit-layout-settings-regions-' . $machine_name . '-element-wrapper-class-enable' => array(TRUE),
      )
    );

  }

//  dargs();
//  dsm($form);

  return $form;
}

function template_preprocess_semantic_panels_onecol(&$vars){
  $settings = $vars['settings'];
  $layout = $vars['layout'];

  $vars['panel_wrapper'] = _semantic_panels_prepare_element_settings($settings['panel']['element_wrapper']);

  if(!empty($settings['element_wrapper']['class'])){
    $vars['classes_array'][] = $settings['element_wrapper']['class'];
  }

}