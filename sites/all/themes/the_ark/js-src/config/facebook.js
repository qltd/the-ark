(function ($) {
  Drupal.behaviors.facebookConfig = {
    attach: function () {
      var button = $('.facebook-share');
      if (button.length === 0) return;

      button.click(function (e) {
        e.preventDefault();
        if (!FB) return;
        var element = $(this);

        FB.ui({
          method: 'feed',
          link: element.prop('href'),
          picture: element.data('image'),
          name: element.data('title'),
          description: element.data('description')
        }, function (response) {});
      });
    }
  };
})(jQuery);
