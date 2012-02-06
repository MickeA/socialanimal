<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<?php /*<div class="panel-display panel-1col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>> */ ?>

<?php if ($panel_wrapper['type']): ?>
  <<?php print $panel_wrapper['type']; ?> class="<?php print $classes; ?>" <?php //print $id; ?>>
<?php endif; ?>

<?php foreach($settings['regions'] as $machine_name => $settings):
      $region_wrapper = _semantic_panels_prepare_element_settings($settings['element_wrapper']);
?>

  <?php if ($region_wrapper['type']): ?>
    <<?php print $region_wrapper['type']; ?> class="<?php print $region_wrapper['class']; ?>" <?php //print $id; ?>>
  <?php endif; ?>

    <div class="panel-panel panel-col">
      <?php print $content[$machine_name]; ?>
    </div>

  <?php if ($region_wrapper['type']): ?>
    </<?php print $region_wrapper['type']; ?>>
  <?php endif; ?>

<?php endforeach; ?>

<?php if ($panel_wrapper['type']): ?>
  </<?php print $panel_wrapper['type']; ?>>
<?php endif; ?>
