(function ($) {


    Drupal.behaviors.brsvFaqToggle = {
    attach: function (context, settings) {
      $("#music-player .views-field-title", context).click(function(e) {
        $('.jp-interface').toggle('fast');
        $('.jp-playlist').toggle('fast');
       // $('.jp-audio').addClass('music-player-hide');
      })
    }
  }


})(jQuery);(500);