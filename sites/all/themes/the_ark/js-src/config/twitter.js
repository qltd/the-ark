(function ($) {
  Drupal.behaviors.theArkTwitterConfig = {
    attach: function () {
      var button = $('.twitter-tweet');
      if (button.length === 0) return;

      button.click(function (e) {
        e.preventDefault();
        var width = 575
          , height = 250
          , left = ($(window).width()  - width)  / 2
          , top = ($(window).height() - height) / 2
          , url = $(this).prop('href')
          , opts = 'status=1' + ',width=' + width + ',height=' + height + ',top=' + top +',left=' + left;

        window.open(url, 'twitter', opts);
        return false;
      });
    }
  };
})(jQuery);
