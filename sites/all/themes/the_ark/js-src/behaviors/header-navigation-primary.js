(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var body = $('body')
        , wrapper = $('.menu-primary-wrapper')
        , navigation = $('.menu-primary-wrapper > .menu')
        , toggle = $('.header-navigation-primary .block__title')
        , buttonClose = $('.menu-primary-close');
      if (wrapper.length === 0 || navigation.length === 0) return;

      var toggleClasses = function (method) {
        body[method]('document-modal');
        toggle[method]('active');
        wrapper[method]('menu-flyout-visible');
        switch (method) {
          case 'addClass':
            $(document).on('touchmove', function (e) {
              e.preventDefault();
            });
            break;
          case 'removeClass':
            $(document).off('touchmove');
            break;
        }
      };

      navigation.on('touchmove', function (e) {
        e.stopPropagation();
      });

      body.on('swiperight', function (e) {
        e.preventDefault();
        toggleClasses('addClass');
      });
      body.on('swipeleft', function (e) {
        e.preventDefault();
        toggleClasses('removeClass');
      });
      toggle.on('tap', function () {
        toggleClasses('addClass');
      });
      buttonClose.on('tap', function () {
        toggleClasses('removeClass');
      });
    }
  };
})(jQuery);
