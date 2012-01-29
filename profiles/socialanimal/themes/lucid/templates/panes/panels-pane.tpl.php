<?php
/**
 * @file
 * Override of the panels-pane template file
 */
?>

<section class="<?php print $classes; ?>" <?php print $id; ?>>

  <?php if ($admin_links): ?>
    <div class="admin-links panel-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>

  <?php if ($title): ?>
    <h2 class="pane-title"><?php print $title; ?></h2>
  <?php endif; ?>

  <?php if ($feeds): ?>
    <div class="feed">
      <?php print $feeds; ?>
    </div>
  <?php endif; ?>

  <?php print render($content); ?>

  <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?php print $more; ?>
    </div>
  <?php endif; ?>

</section>
