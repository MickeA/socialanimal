<?php
?>

<?php if (!empty($css_id)): ?>
  <div id="<?php print $css_id; ?>" class="clearfix">
<?php endif; ?>

<?php if (!empty($content['main'])): ?>
  <div class="page-main grid-10 alpha">
    <div class="sub-region page-main-inner clearfix">
      <?php print render($content['main']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($content['aside_alpha'])): ?>
  <div class="page-aside-alpha grid-6 omega">
    <div class="sub-region page-aside-alpha-inner clearfix">
      <?php print render($content['aside_alpha']); ?>
    </div>
  </div>
<?php endif; ?>

<?php if (!empty($css_id)): ?>
  </div>
<?php endif; ?>
