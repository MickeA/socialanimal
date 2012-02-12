<?php
/**
 * @file
 * To be used inside the site template. No wrappers by default.
 */
?>

<?php #print render($content['main']); ?>


<?php if (!empty($content['branding'])): ?>
  <div class="branding clearfix">
    <?php print render($content['branding']); ?>
  </div>
<?php endif;?>

<?php if (!empty($content['main'])): ?>
  <div class="main clearfix" role="main">
    <?php print render($content['main']); ?>
  </div>
<?php endif; ?>