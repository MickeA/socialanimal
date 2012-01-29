<?php
/**
 * @file
 * field.tpl.php
 *
 * Override of the default template implementation to display the value of a
 * field.
 *
 * @see field.tpl.php
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    <?php endforeach; ?>
</div>
