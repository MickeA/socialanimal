<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-2col-stacked clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top']): ?>
    <div class="panel-col-top panel-panel">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>
  <?php endif; ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="center-wrapper">
      <?php if ($content['left']): ?>
        <div class="panel-col-first panel-panel">
          <div class="inside"><?php print $content['left']; ?></div>
        </div>
      <?php endif; ?>
      <?php if ($content['right']): ?>
        <div class="panel-col-last panel-panel">
          <div class="inside"><?php print $content['right']; ?></div>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($content['bottom']): ?>
    <div class="panel-col-bottom panel-panel">
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>
  <?php endif; ?>
</div>
