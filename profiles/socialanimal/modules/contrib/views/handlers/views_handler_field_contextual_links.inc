<?php

class views_handler_field_contextual_links extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['fields'] = array('default' => array());

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $options = array();
    $options = $this->view->display_handler->get_field_labels();
    $form['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields'),
      '#description' => t('Which fields should be included into the contextu links'),
      '#options' => $options,
      '#default_value' => $this->options['fields'],
    );
  }

  function pre_render(&$values) {
    // Add a row plugin css class for the contextual link.
    $class = 'contextual-links-region';
    if (!empty($this->view->style_plugin->options['row_class'])) {
      $this->view->style_plugin->options['row_class'] .= " $class";
    }
    else {
      $this->view->style_plugin->options['row_class'] = $class;
    }
  }

  /**
   * Render the contextual fields.
   */
  function render($values) {
    $links = array();
    foreach ($this->options['fields'] as $field) {
      if (empty($this->view->field[$field]->last_render_text)) {
        continue;
      }
      $title = $this->view->field[$field]->last_render_text;
      $path = '';
      if (!empty($this->view->field[$field]->options['alter']['path'])) {
        $path = $this->view->field[$field]->options['alter']['path'];
      }
      if (!empty($title)) {
        $links[$field] = array(
          'href' => $path,
          'title' => $title,
          'query' => array(
            'destination' => $_GET['q']
          )
        );
      }
    }
    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
      '#access' => user_access('Use contextual links')
    );

    return drupal_render($build);
  }

  function query() { }
}