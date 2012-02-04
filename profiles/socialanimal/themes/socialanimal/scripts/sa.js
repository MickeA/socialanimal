(function ($) {

// Music player hide/display function
    Drupal.behaviors.SaMusicToggle = {
    attach: function (context, settings) {
      $("#music-player .player-hide-show", context).click(function(e) {
       // $('.jp-interface').toggle('fast');
        $('.jp-playlist, .views-field-field-music-image, .views-field-title').toggle('fast');
       // $('.views-field-field-music-image').toggle('fast');
       // $('.views-field-title').toggle('fast');
      })
    }
  }

// Scale text function
  Drupal.behaviors.saFitText = {
    attach: function (context, settings) {
      $(".pane-page-site-name .pane-content").fitText((0.8), { minFontSize: '50px', maxFontSize: '130px' });
    }
  }


})(jQuery);(500);