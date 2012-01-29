<?php
/**
 * @file
 * Override of the pane-header template file
 */
?>

<?php if ($site_name || $site_slogan): ?>
  <hgroup>
    <h1 id="site-name">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
    </h1>    
    <?php if ($site_slogan): ?>
      <div id="site-slogan"><?php print $site_slogan; ?></div>
    <?php endif; ?>
  </hgroup>
<?php endif; ?>
<?php print render($page['header']); ?>
<?php if (!empty($search_box)): ?>
  <div id="search-box"><?php print $search_box; ?></div>
<?php endif; ?>
<?php print $search_box; ?>
